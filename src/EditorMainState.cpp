/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */

#include <EssexEngineAppEditor/EditorMainState.h>

EssexEngine::Apps::Editor::EditorMainState::EditorMainState(WeakPointer<Context> _context)
: Core::Models::State(_context) {
        aboutWindow = NULL;
        editGameDetailsWindow = NULL;
        editCharactersWindow = NULL;
        editDoodadsWindow = NULL;
        editMapTilesWindow = NULL;
        mapEditorWindow = NULL;
        mapScriptEditorWindow = NULL;
        mapSelectorWindow = NULL;
        packageGameWindow = NULL;
    }

EssexEngine::Apps::Editor::EditorMainState::~EditorMainState() {}

void EssexEngine::Apps::Editor::EditorMainState::Setup() {
    CachedPointer<Daemons::FileSystem::IFileBuffer> gameFile = context->GetDaemon<Daemons::FileSystem::FileSystemDaemon>()->ReadFile(GAME_FILE_LOCATION);
    
    gameDocument = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetJsonDocument(
        gameFile.ToWeakPointer()
    );

    currentMapFile = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetStringFromNode(
        WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()),
        "initialMap"
    );

    CachedPointer<Daemons::FileSystem::IFileBuffer> mapFile = context->GetDaemon<Daemons::FileSystem::FileSystemDaemon>()->ReadFile(currentMapFile);
    
    mapDocument = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetJsonDocument(
        mapFile.ToWeakPointer()
    );
    
    mapEditorWindow = new Windows::MapEditorWindow(
        context,
        WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()),
        WeakPointer<Daemons::Json::IJsonDocument>(mapDocument.get()),
        [this] () { delete mapEditorWindow; mapEditorWindow = NULL; }
    );
}

void EssexEngine::Apps::Editor::EditorMainState::Logic() {
    if(aboutWindow) aboutWindow->Logic();
    
    if(editGameDetailsWindow) editGameDetailsWindow->Logic();
    if(editCharactersWindow) editCharactersWindow->Logic();
    if(editDoodadsWindow) editDoodadsWindow->Logic();
    if(editMapTilesWindow) editMapTilesWindow->Logic();
    
    if(mapEditorWindow) mapEditorWindow->Logic();
    if(mapScriptEditorWindow) mapScriptEditorWindow->Logic();
    if(mapSelectorWindow) mapSelectorWindow->Logic();
    
    if(packageGameWindow) packageGameWindow->Logic();
}

void EssexEngine::Apps::Editor::EditorMainState::Render() {
    RenderMainMenu();
    
    if(aboutWindow) aboutWindow->Render();
    
    if(editGameDetailsWindow) editGameDetailsWindow->Render();
    if(editCharactersWindow) editCharactersWindow->Render();
    if(editDoodadsWindow) editDoodadsWindow->Render();
    if(editMapTilesWindow) editMapTilesWindow->Render();
    
    if(mapEditorWindow) mapEditorWindow->Render();
    if(mapScriptEditorWindow) mapScriptEditorWindow->Render();
    if(mapSelectorWindow) mapSelectorWindow->Render();
    
    if(packageGameWindow) packageGameWindow->Render();
}

bool EssexEngine::Apps::Editor::EditorMainState::PauseUnder() {
    return true;
}

void EssexEngine::Apps::Editor::EditorMainState::RenderMainMenu() {
    if(ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("About")) {
                if(!aboutWindow) {
                    aboutWindow = new Windows::AboutWindow(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), [this] () { delete aboutWindow; aboutWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Exit")) {
                this->completed = true;
            }
            
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Game")) {
            if(ImGui::MenuItem("Edit Game Details")) {
                if(!editGameDetailsWindow) {
                    editGameDetailsWindow = new Windows::EditGameDetailsWindow(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), [this] () { delete editGameDetailsWindow; editGameDetailsWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Edit MapTiles")) {
                if(!editMapTilesWindow) {
                    editMapTilesWindow = new Windows::EditMapTilesWindow(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), [this] () { delete editMapTilesWindow; editMapTilesWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Edit Doodads")) {
                if(!editDoodadsWindow) {
                    editDoodadsWindow = new Windows::EditDoodadsWindow(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), [this] () { delete editDoodadsWindow; editDoodadsWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Edit Characters")) {
                if(!editCharactersWindow) {
                    editCharactersWindow = new Windows::EditCharactersWindow(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), [this] () { delete editCharactersWindow; editCharactersWindow = NULL; });
                }
            }
            
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Map"))
        {
            /*
            if(ImGui::MenuItem("Save Map")) {
                Json::FastWriter fastWriter;
                std::string json = fastWriter.write(mapDocument);
                
                context->fileSystem->SaveFile(
                    currentMapFile,
                    (void*)(json).c_str(),
                    (json).length()
                );
            } else if(ImGui::MenuItem("Update Map Scripts")) {
                mapScriptEditorWindow = new Windows::MapScriptEditorWindow(
                    context,
                    &gameDocument,
                    &mapDocument,
                    currentMapFile,
                    [this] () { delete mapScriptEditorWindow; mapScriptEditorWindow = NULL; }
                );
            } else if(ImGui::MenuItem("Change Map")) {
                mapSelectorWindow = new Windows::MapSelectorWindow(
                    context,
                    &gameDocument,
                    currentMapFile,
                    [this] (std::string map) {
                        currentMapFile = map;
                        ClearMap();
                        LoadMap();
                    },
                    [this] () { delete mapSelectorWindow; mapSelectorWindow = NULL; }
                );
            }
            */
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Export"))
        {
            if(ImGui::MenuItem("Test Game")) {
                context->GetStateStack()->Push(new Game::MapState(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), WeakPointer<Daemons::Json::IJsonDocument>(mapDocument.get())));
            } else if(ImGui::MenuItem("Package Game Data")) {
                if(!aboutWindow) {
                    packageGameWindow = new Windows::PackageGameWindow(context, WeakPointer<Daemons::Json::IJsonDocument>(gameDocument.get()), [this] () { delete packageGameWindow; packageGameWindow = NULL; });
                }
            }
            
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
     }
}

void EssexEngine::Apps::Editor::EditorMainState::ClearMap() {
    delete mapEditorWindow;
}
