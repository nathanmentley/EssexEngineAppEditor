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
    CachedPointer<std::string, Daemons::FileSystem::IFileBuffer> gameFile = context->GetDaemon<Daemons::FileSystem::FileSystemDaemon>()->ReadFile(GAME_FILE_LOCATION);
    
    context->GetDaemon<Daemons::Json::JsonDaemon>()->GetJsonDocument(
        gameFile.ToWeakPointer()
    ).swap(gameDocument);

    currentMapFile = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetStringFromNode(
        gameDocument.ToWeakPointer(),
        "initialMap"
    );

    CachedPointer<std::string, Daemons::FileSystem::IFileBuffer> mapFile = context->GetDaemon<Daemons::FileSystem::FileSystemDaemon>()->ReadFile(currentMapFile);
    
    context->GetDaemon<Daemons::Json::JsonDaemon>()->GetJsonDocument(
        mapFile.ToWeakPointer()
    ).swap(mapDocument);
    
    mapEditorWindow = new Windows::MapEditorWindow(
        context,
        gameDocument.ToWeakPointer(),
        mapDocument.ToWeakPointer(),
        [this] () { delete mapEditorWindow; mapEditorWindow = NULL; }
    );
}

void EssexEngine::Apps::Editor::EditorMainState::Logic() {
    if(mapEditorWindow) mapEditorWindow->Logic();
}

void EssexEngine::Apps::Editor::EditorMainState::Render() {
    if(mapEditorWindow) mapEditorWindow->Render();
    RenderMainMenu();
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
                    aboutWindow = new Windows::AboutWindow(context, gameDocument.ToWeakPointer(), [this] () { delete aboutWindow; aboutWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Exit")) {
                this->completed = true;
            }
            
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Game")) {
            if(ImGui::MenuItem("Edit Game Details")) {
                if(!editGameDetailsWindow) {
                    editGameDetailsWindow = new Windows::EditGameDetailsWindow(context, gameDocument.ToWeakPointer(), [this] () { delete editGameDetailsWindow; editGameDetailsWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Edit MapTiles")) {
                if(!editMapTilesWindow) {
                    editMapTilesWindow = new Windows::EditMapTilesWindow(context, gameDocument.ToWeakPointer(), [this] () { delete editMapTilesWindow; editMapTilesWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Edit Doodads")) {
                if(!editDoodadsWindow) {
                    editDoodadsWindow = new Windows::EditDoodadsWindow(context, gameDocument.ToWeakPointer(), [this] () { delete editDoodadsWindow; editDoodadsWindow = NULL; });
                }
            } else if(ImGui::MenuItem("Edit Characters")) {
                if(!editCharactersWindow) {
                    editCharactersWindow = new Windows::EditCharactersWindow(context, gameDocument.ToWeakPointer(), [this] () { delete editCharactersWindow; editCharactersWindow = NULL; });
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
                context->GetStateStack()->Push(new Game::MapState(context, gameDocument.ToWeakPointer(), mapDocument.ToWeakPointer()));
            } else if(ImGui::MenuItem("Package Game Data")) {
                if(!aboutWindow) {
                    packageGameWindow = new Windows::PackageGameWindow(context, gameDocument.ToWeakPointer(), [this] () { delete packageGameWindow; packageGameWindow = NULL; });
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
