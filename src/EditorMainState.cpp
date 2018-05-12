/* 
 * Essex Engine
 * 
 * Copyright (C) 2018 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */

#include <EssexEngineAppEditor/EditorMainState.h>

using EssexEngine::Core::IApp;
using EssexEngine::Core::Models::State;

using EssexEngine::Daemons::FileSystem::IFileBuffer;
using EssexEngine::Daemons::Json::IJsonDocument;

using EssexEngine::Daemons::FileSystem::FileSystemDaemon;
using EssexEngine::Daemons::Json::JsonDaemon;

using EssexEngine::Apps::Editor::EditorMainState;

using EssexEngine::Apps::Editor::Windows::AboutWindow;
using EssexEngine::Apps::Editor::Windows::EditGameDetailsWindow;
using EssexEngine::Apps::Editor::Windows::EditCharactersWindow;
using EssexEngine::Apps::Editor::Windows::EditDoodadsWindow;
using EssexEngine::Apps::Editor::Windows::EditMapTilesWindow;
using EssexEngine::Apps::Editor::Windows::MapEditorWindow;
using EssexEngine::Apps::Editor::Windows::MapScriptEditorWindow;
using EssexEngine::Apps::Editor::Windows::MapSelectorWindow;
using EssexEngine::Apps::Editor::Windows::PackageGameWindow;

EditorMainState::EditorMainState(WeakPointer<Context> _context, WeakPointer<IApp> _app):
    State(_context, _app),
    gameDocument(
        _context->GetDaemon<JsonDaemon>()->GetJsonDocument(
            _context->GetDaemon<FileSystemDaemon>()->ReadFile(GAME_FILE_LOCATION).ToWeakPointer()
        )
    ),
    currentMapFile(
        _context->GetDaemon<JsonDaemon>()->GetStringFromNode(
            gameDocument.ToWeakPointer(),
            "initialMap"
        )
    ),
    mapDocument(
        _context->GetDaemon<JsonDaemon>()->GetJsonDocument(
            _context->GetDaemon<FileSystemDaemon>()->ReadFile(currentMapFile).ToWeakPointer()
        )
    ),
    aboutWindow(
        UniquePointer<AboutWindow>()
    ),
    editGameDetailsWindow(
        UniquePointer<EditGameDetailsWindow>()
    ),
    editCharactersWindow(
        UniquePointer<EditCharactersWindow>()
    ),
    editDoodadsWindow(
        UniquePointer<EditDoodadsWindow>()
    ),
    editMapTilesWindow(
        UniquePointer<EditMapTilesWindow>()
    ),
    mapEditorWindow(
        UniquePointer<MapEditorWindow>()
    ),
    mapScriptEditorWindow(
        UniquePointer<MapScriptEditorWindow>()
    ),
    mapSelectorWindow(
        UniquePointer<MapSelectorWindow>()
    ),
    packageGameWindow(
        UniquePointer<PackageGameWindow>()
    ){}

EditorMainState::~EditorMainState() {}

void EditorMainState::Setup() {
    mapEditorWindow.Replace(
        new Windows::MapEditorWindow(
            context,
            gameDocument.ToWeakPointer(),
            mapDocument.ToWeakPointer(),
            [this] () { mapEditorWindow.Reset(); }
        )
    );
}

void EditorMainState::Logic() {
    if(mapEditorWindow.HasValue()) {
        mapEditorWindow->Logic();
    }
}

void EditorMainState::Render() {
    if(mapEditorWindow.HasValue()) {
        mapEditorWindow->Render();
    }

    RenderMainMenu();
}

bool EditorMainState::PauseUnder() {
    return true;
}

void EditorMainState::RenderMainMenu() {
    /*
    if(ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("About")) {
                if(!aboutWindow) {
                    aboutWindow.Replace(
                        new Windows::AboutWindow(
                            context,
                            gameDocument.ToWeakPointer(),
                            [this] () {
                                aboutWindow.Reset();
                            }
                        )
                    );
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
    */
}
