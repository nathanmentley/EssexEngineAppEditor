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

#include <EssexEngineAppEditor/EditCharactersWindow.h>

EssexEngine::Apps::Editor::Windows::EditCharactersWindow::EditCharactersWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
    characters = std::vector<characterdef>();
    /*
    std::list<std::unique_ptr<Daemons::Json::IJsonNode>> charactersInFile = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetJsonNodeArray(gameDocument, "characters");
    for(auto& characterInFile : charactersInFile) {
        characterdef character = characterdef();
        character.filenamebody = new char[512];
        character.filenamehead = new char[512];
        character.filenameweapon = new char[512];
        
        std::string filenamebody = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetStringFromNode(characterInFile, "filenamebody");
        std::string filenamehead = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetStringFromNode(characterInFile, "filenamehead");
        std::string filenameweapon = context->GetDaemon<Daemons::Json::JsonDaemon>()->GetStringFromNode(characterInFile, "filenameweapon");
        strcpy(character.filenamebody, filenamebody.c_str());
        strcpy(character.filenamehead, filenamehead.c_str());
        strcpy(character.filenameweapon, filenameweapon.c_str());
        
        characters.push_back(character);
    }*/
}

EssexEngine::Apps::Editor::Windows::EditCharactersWindow::~EditCharactersWindow() {
    for(auto &character : characters) {
        delete[] character.filenamebody;
        delete[] character.filenamehead;
        delete[] character.filenameweapon;
    }
}

void EssexEngine::Apps::Editor::Windows::EditCharactersWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::EditCharactersWindow::Render() {
    /*
    ImGui::Begin("Character Editor", NULL, ImGuiWindowFlags_ShowBorders );
    int i = 0;
    for(auto &character : characters) {
        i++;
        ImGui::Text("character: %d", i);
        
        //ImGui::InputText(string_format("filename body %d", i).c_str(), character.filenamebody, 512);
        //ImGui::InputText(string_format("filename head %d", i).c_str(), character.filenamehead, 512);
        //ImGui::InputText(string_format("filename weapon %d", i).c_str(), character.filenameweapon, 512);
    }
    
    
    if(ImGui::Button("Add New")) {
        characterdef character = characterdef();
        
        character.filenamebody = new char[512];
        character.filenamehead = new char[512];
        character.filenameweapon = new char[512];
        
        characters.push_back(character);
    }
    
    
    if(ImGui::Button("Cancel")) {
        close();
    }
    if(ImGui::Button("Save")) {
        context->GetDaemon<Daemons::Json::JsonDaemon>()->RemoveNode(gameDocument, "characters");
        std::unique_ptr<Daemons::Json::IJsonNode> charactersNode = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
        context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToArray(charactersNode);
            
        std::vector<characterdef>::iterator iter = characters.begin();
        std::vector<characterdef>::iterator eiter = characters.end();
        for (; iter != eiter; ++iter)
        {
            std::unique_ptr<Daemons::Json::IJsonNode> characterNode = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            
            std::unique_ptr<Daemons::Json::IJsonNode> bodyNode = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToString(bodyNode, Nullable<std::string>((*iter).filenamebody));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(characterNode, bodyNode, "filenamebody");
            
            std::unique_ptr<Daemons::Json::IJsonNode> headNode = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToString(headNode, Nullable<std::string>((*iter).filenamehead));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(characterNode, headNode, "filenamehead");
            
            std::unique_ptr<Daemons::Json::IJsonNode> weaponNode = context->GetDaemon<Daemons::Json::JsonDaemon>()->CreateNode();
            context->GetDaemon<Daemons::Json::JsonDaemon>()->SetNodeToString(weaponNode, Nullable<std::string>((*iter).filenameweapon));
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendNode(characterNode, weaponNode, "filenameweapon");
            
            context->GetDaemon<Daemons::Json::JsonDaemon>()->AppendToArray(gameDocument, characterNode, "characters");
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
    */
}
