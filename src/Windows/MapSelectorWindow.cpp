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

#include <EssexEngineAppEditor/MapSelectorWindow.h>

EssexEngine::Apps::Editor::Windows::MapSelectorWindow::MapSelectorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::string _currentMapFile, std::function<void(std::string)> _changeMap, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
    changeMap = _changeMap;
    maps = std::vector<std::string>();
    /*
    std::list<Daemons::Json::IJsonNode*> mapsInFile = _context->json->GetJsonNodeArray(gameDocument, "maps");
    for(auto& mapInFile : mapsInFile) {
        std::string map = _context->json->GetStringFromNode(mapInFile);
        maps.push_back(map);
    }
    */
    selectedMap = find(maps.begin(), maps.end(), _currentMapFile) - maps.begin();
}

EssexEngine::Apps::Editor::Windows::MapSelectorWindow::~MapSelectorWindow() {
}

void EssexEngine::Apps::Editor::Windows::MapSelectorWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::MapSelectorWindow::Render() {
    ImGui::Begin("Map Selector");
    
    ImGui::Combo(
        "selected map",
        &selectedMap,
        [](void* data, int idx, const char** out_text) {
            std::vector<std::string>* maps = (std::vector<std::string>*)data;
            *out_text = (*maps)[idx].c_str();
            return true;
        },
        (void*)&maps,
        maps.size()
    );
    
    if(ImGui::Button("New Map")) {
    }
    if(ImGui::Button("Close")) {
        close();
    }
    if(ImGui::Button("Change")) {
        changeMap(maps[selectedMap]);
        close();
    }
    ImGui::End();
}
