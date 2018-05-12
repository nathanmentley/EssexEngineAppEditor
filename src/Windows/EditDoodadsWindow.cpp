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

#include <EssexEngineAppEditor/EditDoodadsWindow.h>

EssexEngine::Apps::Editor::Windows::EditDoodadsWindow::EditDoodadsWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
    doodads = std::vector<doodaddef>();
    /*
    const Json::Value doodadsInFile = (*gameDocument)["doodads"];
    for (int i = 0; i < doodadsInFile.size(); i++) {
        doodaddef doodad = doodaddef();
        
        doodad.filename = new char[512];
        strcpy(doodad.filename, ((std::string)doodadsInFile[i]["filename"].asString()).c_str());
        doodad.spritexposition = doodadsInFile[i]["spritexposition"].asInt();
        doodad.spriteyposition = doodadsInFile[i]["spriteyposition"].asInt();
        doodad.spritewidth = doodadsInFile[i]["spritewidth"].asInt();
        doodad.spriteheight = doodadsInFile[i]["spriteheight"].asInt();
        
        doodads.push_back(doodad);
    }*/
}

EssexEngine::Apps::Editor::Windows::EditDoodadsWindow::~EditDoodadsWindow() {
    for(auto &doodad : doodads) {
        delete[] doodad.filename;
    }
}

void EssexEngine::Apps::Editor::Windows::EditDoodadsWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::EditDoodadsWindow::Render() {
    /*
    ImGui::Begin("Doodad Editor", NULL, ImGuiWindowFlags_ShowBorders );
    
    int i = 0;
    for(auto &doodad : doodads) {
        i++;
        ImGui::Text("doodad: %d", i);
        
        //ImGui::InputText(string_format("filename %d", i).c_str(), doodad.filename, 512);
        //ImGui::InputInt(string_format("x pos %d", i).c_str(), &(doodad.spritexposition));
        //ImGui::InputInt(string_format("y pos %d", i).c_str(), &(doodad.spriteyposition));
        //ImGui::InputInt(string_format("width %d", i).c_str(), &(doodad.spritewidth));
        //ImGui::InputInt(string_format("height %d", i).c_str(), &(doodad.spriteheight));
    }
    
    if(ImGui::Button("Add New")) {
        doodaddef doodad = doodaddef();
        
        doodad.filename = new char[512];
        
        doodads.push_back(doodad);
    }
    
    
    if(ImGui::Button("Cancel")) {
        close();
    }
    if(ImGui::Button("Save")) {
        if(gameDocument->isObject()) {
            (*gameDocument).removeMember("doodads");
            
            (*gameDocument)["doodads"] = Json::Value(Json::arrayValue);
            
            std::vector<doodaddef>::iterator iter = doodads.begin();
            std::vector<doodaddef>::iterator eiter = doodads.end();
            for (; iter != eiter; ++iter)
            {
                Json::Value* doodad = new Json::Value();
                
                (*doodad)["filename"] = (*iter).filename;
                
                (*doodad)["spritexposition"] = (*iter).spritexposition;
                (*doodad)["spriteyposition"] = (*iter).spriteyposition;
                (*doodad)["spritewidth"] = (*iter).spritewidth;
                (*doodad)["spriteheight"] = (*iter).spriteheight;
                
                (*gameDocument)["doodads"].append(*doodad);
            }
            
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
