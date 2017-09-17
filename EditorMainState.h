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
            void LoadMap();
            void ClearMap();
        private:
            UniquePointer<Daemons::Json::IJsonDocument> gameDocument;
            SharedPointer<Daemons::FileSystem::IFileBuffer> gameFile;
            UniquePointer<Daemons::Json::IJsonDocument> mapDocument;
            SharedPointer<Daemons::FileSystem::IFileBuffer> mapFile;
            std::string currentMapFile;
        
            Windows::AboutWindow* aboutWindow;
            Windows::EditGameDetailsWindow* editGameDetailsWindow;
            Windows::EditCharactersWindow* editCharactersWindow;
            Windows::EditDoodadsWindow* editDoodadsWindow;
            Windows::EditMapTilesWindow* editMapTilesWindow;
            Windows::MapEditorWindow* mapEditorWindow;
            Windows::MapScriptEditorWindow* mapScriptEditorWindow;
            Windows::MapSelectorWindow* mapSelectorWindow;
            Windows::PackageGameWindow* packageGameWindow;
	};
}}};