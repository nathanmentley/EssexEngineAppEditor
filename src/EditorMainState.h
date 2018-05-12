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
#pragma once

#include <EssexEngineCore/State.h>
#include <EssexEngineGfxDaemon/Entity.h>

#include <EssexEngineLibIsoMap/Map.h>

#include <EssexEngineAppGame/MapState.h>

#include <EssexEngineAppEditor/AboutWindow.h>
#include <EssexEngineAppEditor/EditGameDetailsWindow.h>
#include <EssexEngineAppEditor/EditCharactersWindow.h>
#include <EssexEngineAppEditor/EditDoodadsWindow.h>
#include <EssexEngineAppEditor/EditMapTilesWindow.h>
#include <EssexEngineAppEditor/MapEditorWindow.h>
#include <EssexEngineAppEditor/MapScriptEditorWindow.h>
#include <EssexEngineAppEditor/MapSelectorWindow.h>
#include <EssexEngineAppEditor/PackageGameWindow.h>
#include <EssexEngineAppEditor/Daemons.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
    class EditorMainState:public Core::Models::State
    {
        public:
            EditorMainState(WeakPointer<Context> _context);
            ~EditorMainState();
            
            //override
            void Setup();
            void Logic();
            void Render();
            bool PauseUnder();
        protected:
            void RenderMainMenu();
        private:
            UniquePointer<Daemons::Json::IJsonDocument> gameDocument;
            std::string currentMapFile;
            UniquePointer<Daemons::Json::IJsonDocument> mapDocument;
        
            UniquePointer<Windows::AboutWindow> aboutWindow;
            UniquePointer<Windows::EditGameDetailsWindow> editGameDetailsWindow;
            UniquePointer<Windows::EditCharactersWindow> editCharactersWindow;
            UniquePointer<Windows::EditDoodadsWindow> editDoodadsWindow;
            UniquePointer<Windows::EditMapTilesWindow> editMapTilesWindow;
            UniquePointer<Windows::MapEditorWindow> mapEditorWindow;
            UniquePointer<Windows::MapScriptEditorWindow> mapScriptEditorWindow;
            UniquePointer<Windows::MapSelectorWindow> mapSelectorWindow;
            UniquePointer<Windows::PackageGameWindow> packageGameWindow;
    };
}}};
