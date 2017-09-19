//
//  Entry.cpp
//  EssexEngine
//

#include <EssexEngineAppEditor/EditorApp.h>
#include <EssexEngineAppEditor/EditorMainState.h>

extern "C" {
    void app_init(EssexEngine::Context* context) {
        context->RegisterApp(
            new EssexEngine::Apps::Editor::EditorApp(
                new EssexEngine::Apps::Editor::EditorMainState(context)
            )
        );
    }
}