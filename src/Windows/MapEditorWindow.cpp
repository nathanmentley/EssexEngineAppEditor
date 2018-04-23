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

#include <EssexEngineAppEditor/MapEditorWindow.h>

EssexEngine::Apps::Editor::Windows::MapEditorWindow::MapEditorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, WeakPointer<Daemons::Json::IJsonDocument> _mapDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close), 
    selectedTileOverlay(
        _context->GetDaemon<Daemons::Gfx::GfxDaemon>()->GetEntity(
            _context->GetDaemon<Daemons::Gfx::GfxDaemon>()->GetSprite(
                _context->GetDaemon<Daemons::FileSystem::FileSystemDaemon>()->ReadFile(
                    "content/root/Tilesets/grassland_tiles.png"
                ),
                364,
                345,
                Libs::IsoMap::MapTile::TILE_WIDTH,
                Libs::IsoMap::MapTile::TILE_HEIGHT
            )
        )
    )
{
    mapDocument = _mapDocument;
    
    map = new Libs::IsoMap::Map(context, _gameDocument, mapDocument);
    activeTab = 0;
}

EssexEngine::Apps::Editor::Windows::MapEditorWindow::~MapEditorWindow() {
    delete map;
}

void EssexEngine::Apps::Editor::Windows::MapEditorWindow::Logic() {
    //process input.
    if(context->GetDaemon<Daemons::Input::InputDaemon>()->IsKeyPressed(Daemons::Input::KeyboardButton::Up)) {
        map->SetScreenX(map->GetScreenX() + .1);
        map->SetScreenY(map->GetScreenY() + .1);
    }
    if(context->GetDaemon<Daemons::Input::InputDaemon>()->IsKeyPressed(Daemons::Input::KeyboardButton::Down)) {
        map->SetScreenX(map->GetScreenX() - .1);
        map->SetScreenY(map->GetScreenY() - .1);
    }
    if(context->GetDaemon<Daemons::Input::InputDaemon>()->IsKeyPressed(Daemons::Input::KeyboardButton::Left)) {
        map->SetScreenX(map->GetScreenX() + .1);
        map->SetScreenY(map->GetScreenY() - .1);
    }
    if(context->GetDaemon<Daemons::Input::InputDaemon>()->IsKeyPressed(Daemons::Input::KeyboardButton::Right)) {
        map->SetScreenX(map->GetScreenX() - .1);
        map->SetScreenY(map->GetScreenY() + .1);
    }
}

void EssexEngine::Apps::Editor::Windows::MapEditorWindow::Render() {
    map->Render(context->GetDaemon<Daemons::Gfx::GfxDaemon>()->GetPrimaryRenderContext());//render map
    
    WeakPointer<Daemons::Gfx::Entity> entity = selectedTileOverlay.ToWeakPointer();

    entity->SetPosition(
        map->GetScreenX(
            context->GetDaemon<Daemons::Gfx::GfxDaemon>()->GetPrimaryRenderContext(),
            floor(map->GetScreenX()),
            floor(map->GetScreenY())
        ),
        map->GetScreenY(
            context->GetDaemon<Daemons::Gfx::GfxDaemon>()->GetPrimaryRenderContext(),
            floor(map->GetScreenX()),
            floor(map->GetScreenY())
        )
    );

    context->GetDaemon<Daemons::Gfx::GfxDaemon>()->RenderEntity(context->GetDaemon<Daemons::Gfx::GfxDaemon>()->GetPrimaryRenderContext(), entity);
    
    //render window
    /*
    ImGui::Begin("Map Editor");
    
    if(ImGui::RadioButton("MapTiles", &activeTab, 0)) {
    } else if(ImGui::RadioButton("Doodads", &activeTab, 1)) {
    } else if(ImGui::RadioButton("Characters", &activeTab, 2)) {
    } else if(ImGui::RadioButton("Players", &activeTab, 3)) {
    }
    
    switch(activeTab) {
        case 0: {
                const Json::Value tilesInFile = (*gameDocument)["tiles"];
                for (int i = 0; i < tilesInFile.size(); i++) {
                    if(ImGui::Button(string_format("tile: %d", i + 1).c_str())) {
                        UpdateTile(i);
                    }
                }
            }
            break;
        case 1: {
                const Json::Value doodadsInFile = (*gameDocument)["doodads"];
                for (int i = 0; i < doodadsInFile.size(); i++) {
                    if(ImGui::Button(string_format("doodad: %d", i + 1).c_str())) {
                        UpdateDoodads(i);
                    }
                }
            }
            break;
        case 2: {
            const Json::Value charactersInFile = (*gameDocument)["characters"];
            for (int i = 0; i < charactersInFile.size(); i++) {
                if(ImGui::Button(string_format("characters: %d", i + 1).c_str())) {
                    UpdateCharacter(i);
                }
            }
        }
            break;
        case 3: {
                const Json::Value charactersInFile = (*gameDocument)["characters"];
                for (int i = 0; i < charactersInFile.size(); i++) {
                    if(ImGui::Button(string_format("characters: %d", i + 1).c_str())) {
                        UpdatePlayer(i);
                    }
                }
            }
            break;
    }
    
    ImGui::End();
    */
}


void EssexEngine::Apps::Editor::Windows::MapEditorWindow::UpdateTile(int id) {
    int x = map->GetScreenX();
    int y = map->GetScreenY();
    /*
    Json::Value tilesInFile = (*mapDocument)["maptiles"];
    for (int i = 0; i < tilesInFile.size(); i++) {
        
        if(tilesInFile[i]["x"].asInt() == x && tilesInFile[i]["y"].asInt() == y) {
            tilesInFile[i]["tile"] = id;
            
            (*mapDocument).removeMember("maptiles");
            (*mapDocument)["maptiles"] = tilesInFile;
        }
    }
    */
    RefreshMap();
}
void EssexEngine::Apps::Editor::Windows::MapEditorWindow::UpdateDoodads(int id) {
    int x = map->GetScreenX();
    int y = map->GetScreenY();
    bool updated = false;
    /*
    Json::Value doodadsInFile = (*mapDocument)["doodads"];
    for (int i = 0; i < doodadsInFile.size(); i++) {
        
        if(doodadsInFile[i]["x"].asInt() == x && doodadsInFile[i]["y"].asInt() == y) {
            doodadsInFile[i]["doodad"] = id;
            
            (*mapDocument).removeMember("doodads");
            (*mapDocument)["doodads"] = doodadsInFile;
            
            updated = true;
        }
    }
    
    if(!updated) {
        Json::Value doodadsInFile = (*mapDocument)["doodads"];
        
        Json::Value newDoodad;
        newDoodad["x"] = x;
        newDoodad["y"] = y;
        newDoodad["h"] = 1;
        newDoodad["w"] = 1;
        newDoodad["doodad"] = id;
        
        doodadsInFile.append(newDoodad);
        
        (*mapDocument).removeMember("doodads");
        (*mapDocument)["doodads"] = doodadsInFile;
    }
    */
    RefreshMap();
}
void EssexEngine::Apps::Editor::Windows::MapEditorWindow::UpdateCharacter(int id) {
    int x = map->GetScreenX();
    int y = map->GetScreenY();
    bool updated = false;
    /*
    Json::Value charactersInFile = (*mapDocument)["npcs"];
    
    for (int i = 0; i < charactersInFile.size(); i++) {
        
        if(charactersInFile[i]["x"].asInt() == x && charactersInFile[i]["y"].asInt() == y) {
            charactersInFile[i]["character"] = id;
            
            (*mapDocument).removeMember("npcs");
            (*mapDocument)["npcs"] = charactersInFile;
            
            updated = true;
        }
    }
    
    if(!updated) {
        Json::Value newCharacter;
        newCharacter["x"] = x;
        newCharacter["y"] = y;
        newCharacter["h"] = 1;
        newCharacter["w"] = 1;
        newCharacter["character"] = id;
        
        charactersInFile.append(newCharacter);
        
        (*mapDocument).removeMember("npcs");
        (*mapDocument)["npcs"] = charactersInFile;
    }
    */
    RefreshMap();
}
void EssexEngine::Apps::Editor::Windows::MapEditorWindow::UpdatePlayer(int id) {
    int x = map->GetScreenX();
    int y = map->GetScreenY();
    /*
    (*mapDocument)["player"]["character"] = id;
    (*mapDocument)["player"]["x"] = x;
    (*mapDocument)["player"]["y"] = y;
    */
    RefreshMap();
}

void EssexEngine::Apps::Editor::Windows::MapEditorWindow::RefreshMap() {
    //TODO: Update calls to this to instead of refreshing map... update the map data so this changes will be more fluid.
    
    double screenX = map->GetScreenX();
    double screenY = map->GetScreenY();
    delete map;
    map = new Libs::IsoMap::Map(context, gameDocument, mapDocument);
    map->SetScreenX(screenX);
    map->SetScreenY(screenY);
}
