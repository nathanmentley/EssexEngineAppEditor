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

#include <EssexEngineAppEditor/EditGameDetailsWindow.h>

EssexEngine::Apps::Editor::Windows::EditGameDetailsWindow::EditGameDetailsWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
    //gameName = new char[256];
    //maps = std::vector<std::string>();
    /*
    _context->json->GetStringFromNode(gameDocument, "name");
    
    std::string nameFromFile = _context->json->GetStringFromNode(gameDocument, "name");
    std::string mapFromFile = _context->json->GetStringFromNode(gameDocument, "initialMap");
    strcpy(gameName, nameFromFile.c_str());
    
    std::list<Daemons::Json::IJsonNode*> mapsInFile = _context->json->GetJsonNodeArray(gameDocument, "maps");
    for(auto& mapInFile : mapsInFile) {
        
        maps.push_back(_context->json->GetStringFromNode(mapInFile));
    }
        
    selectedMap = find(maps.begin(), maps.end(), mapFromFile) - maps.begin();*/
}

EssexEngine::Apps::Editor::Windows::EditGameDetailsWindow::~EditGameDetailsWindow()
{
    //delete gameName;
}

void EssexEngine::Apps::Editor::Windows::EditGameDetailsWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::EditGameDetailsWindow::Render() {
    /*
    ImGui::Begin("Game Info Editor", NULL, ImGuiWindowFlags_ShowBorders );
    ImGui::InputText("GameName", gameName, 256);
    
    ImGui::Combo(
        "initialMap",
        &selectedMap,
        [](void* data, int idx, const char** out_text) {
            std::vector<std::string>* maps = (std::vector<std::string>*)data;
            *out_text = (*maps)[idx].c_str();
            return true;
        },
        (void*)&maps,
        maps.size()
    );
    
    if(ImGui::Button("Cancel")) {
        close();
    }
    if(ImGui::Button("Save")) {
        if(gameDocument->isObject()) {
            (*gameDocument)["name"] = gameName;
            (*gameDocument)["initialMap"] = maps[selectedMap];
            
            Json::FastWriter fastWriter;
            std::string json = fastWriter.write(*gameDocument);
            
            context->fileSystem->SaveFile(
                GAME_FILE_LOCATION,
                (void*)(json).c_str(),
                (json).length()
             );
            close();
        }
    }
    ImGui::End();
    */
}
