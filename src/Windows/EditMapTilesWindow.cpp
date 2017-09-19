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

#include <EssexEngineAppEditor/EditMapTilesWindow.h>

EssexEngine::Apps::Editor::Windows::EditMapTilesWindow::EditMapTilesWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
    tiles = std::vector<maptiledef>();
    
    std::list<UniquePointer<Daemons::Json::IJsonNode>> tilesInFile = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetJsonNodeArray(gameDocument, "tiles");
    
    for(auto& tileInFile : tilesInFile) {
        maptiledef tile = maptiledef();
        tile.filename = new char[512];
        
        std::string filename = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetStringFromNode(tileInFile.GetWeakPointer(), "filename");
        strcpy(tile.filename, filename.c_str());
        tile.x = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetIntFromNode(tileInFile.GetWeakPointer(), "spritexposition");
        tile.y = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetIntFromNode(tileInFile.GetWeakPointer(), "spriteyposition");
        tile.blocking = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetBoolFromNode(tileInFile.GetWeakPointer(), "blocking");
        
        tiles.push_back(tile);
    }
}

EssexEngine::Apps::Editor::Windows::EditMapTilesWindow::~EditMapTilesWindow() {
    for(auto &tile : tiles) {
        delete[] tile.filename;
    }
}

void EssexEngine::Apps::Editor::Windows::EditMapTilesWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::EditMapTilesWindow::Render() {
    ImGui::Begin("Map Tile Editor", NULL, ImGuiWindowFlags_ShowBorders );
    
    int i = 0;
    for(auto &tile : tiles) {
        i++;
        ImGui::Text("Tile Data: %d", i);
        
        //ImGui::InputText(string_format("filename %d", i).c_str(), tile.filename, 512);
        //ImGui::InputInt(string_format("x %d", i).c_str(), &(tile.x));
        //ImGui::InputInt(string_format("y %d", i).c_str(), &(tile.y));
        //ImGui::Checkbox(string_format("blocking %d", i).c_str(), &(tile.blocking));
    }
    
    
    if(ImGui::Button("Add New")) {
        maptiledef newTile = maptiledef();
        newTile.filename = new char[512];
        tiles.push_back(newTile);
    }
    
    if(ImGui::Button("Cancel")) {
        close();
    }
    if(ImGui::Button("Save")) {
        context->GetDaemon<Daemons::Json::JsonDaemon>()->RemoveNode(gameDocument, "tiles");
        
        UniquePointer<Daemons::Json::IJsonNode> tilesNode = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
        context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToArray(tilesNode);
        context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(gameDocument, tilesNode, "tiles");
        
        std::vector<maptiledef>::iterator iter = tiles.begin();
        std::vector<maptiledef>::iterator eiter = tiles.end();
        for (; iter != eiter; ++iter)
        {
            UniquePointer<Daemons::Json::IJsonNode> node = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            
            UniquePointer<Daemons::Json::IJsonNode> filename = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToString(filename, Nullable<std::string>((*iter).filename));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(node, filename, "filename");
            
            UniquePointer<Daemons::Json::IJsonNode> xpos = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToInt(xpos, Nullable<int>((*iter).x));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(node, xpos, "spritexposition");
            
            UniquePointer<Daemons::Json::IJsonNode> ypos = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToInt(ypos, Nullable<int>((*iter).y));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(node, ypos, "spriteyposition");
            
            UniquePointer<Daemons::Json::IJsonNode> blocking = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToBool(blocking, Nullable<bool>((*iter).blocking));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(node, blocking, "blocking");
                
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendToArray(gameDocument, node, "tiles");
        }
            
        std::string json = context->GetDaemon<Daemons::Json::JsonDaemon>()->SerializeDocument(gameDocument);
        context->GetDaemon<Daemons::FileSystem::FileSystemDaemon>()->SaveFile(
            GAME_FILE_LOCATION,
            (void*)(json).c_str(),
            (json).length()
        );
        close();
    }
    ImGui::End();
}
