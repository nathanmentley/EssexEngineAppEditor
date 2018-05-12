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

#include <EssexEngineAppEditor/MapScriptEditorWindow.h>

EssexEngine::Apps::Editor::Windows::MapScriptEditorWindow::MapScriptEditorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, Daemons::Json::IJsonDocument* _mapDocument, std::string _currentMapFile, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
    //mapDocument = _mapDocument;
    //currentMapFile = _currentMapFile;
    
    //scripts = std::map<std::string, std::vector<scriptdef>>();
    /*
    const Json::Value scriptHooks = (*gameDocument)["scriptHooks"];
    for (int i = 0; i < scriptHooks.size(); i++) {
        scripts[scriptHooks[i].asString()] = std::vector<scriptdef>();
    }
    
    const Json::Value scriptsInFile = (*mapDocument)["scripts"];
    for (int i = 0; i < scriptsInFile.size(); i++) {
        scriptdef* scriptInFile = new scriptdef();
        
        scriptInFile->name = new char[MAX_SCRIPT_NAME_SIZE];
        scriptInFile->code = new char[MAX_SCRIPT_CODE_SIZE];
        
        strcpy(scriptInFile->name, scriptsInFile[i]["name"].asString().c_str());
        strcpy(scriptInFile->code, scriptsInFile[i]["logic"].asString().c_str());
        
        scripts[scriptsInFile[i]["type"].asString()].push_back(*scriptInFile);
    }*/
}

EssexEngine::Apps::Editor::Windows::MapScriptEditorWindow::~MapScriptEditorWindow() {
}

void EssexEngine::Apps::Editor::Windows::MapScriptEditorWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::MapScriptEditorWindow::Render() {
    /*
    ImGui::Begin("Script Editor");
    
    int i = 0;
    for (std::map<std::string, std::vector<scriptdef>>::iterator it = scripts.begin(); it != scripts.end(); ++it)  {
        ImGui::Text("%s", it->first.c_str());
        
        for(std::vector<scriptdef>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            i++;
            //ImGui::InputText(string_format("Name %d", i).c_str(), it2->name, MAX_SCRIPT_NAME_SIZE);
            //ImGui::InputTextMultiline(string_format("Code %d", i).c_str(), it2->code, MAX_SCRIPT_CODE_SIZE);
        }
        
        if(ImGui::Button(string_format("Add New %s", it->first.c_str()).c_str())) {
            scriptdef def = scriptdef();
            def.name = new char[MAX_SCRIPT_NAME_SIZE];
            def.code = new char[MAX_SCRIPT_CODE_SIZE];
            scripts[it->first].push_back(def);
        }
    }
    
    if(ImGui::Button("Cancel")) {
        close();
    }
    if(ImGui::Button("Save")) {
        if(mapDocument->isObject()) {
            (*mapDocument).removeMember("scriptHooks");
            
            (*mapDocument)["scripts"] = Json::Value(Json::arrayValue);
            
            for (std::map<std::string, std::vector<scriptdef>>::iterator it = scripts.begin(); it != scripts.end(); ++it) {
                for(auto &script : it->second) {
                    Json::Value* scriptnode = new Json::Value();
                    
                    (*scriptnode)["type"] = it->first;
                    (*scriptnode)["name"] = script.name;
                    (*scriptnode)["logic"] = script.code;
                    
                    (*mapDocument)["scripts"].append(*scriptnode);
                }
            }
            
            Json::FastWriter fastWriter;
            std::string json = fastWriter.write(*mapDocument);
            
            context->fileSystem->SaveFile(
                currentMapFile,
                (void*)(json).c_str(),
                (json).length()
            );
        }
        close();
    }
    ImGui::End();
    */
}

