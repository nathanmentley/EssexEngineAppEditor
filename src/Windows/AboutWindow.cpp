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
 
#include <EssexEngineAppEditor/AboutWindow.h>

EssexEngine::Apps::Editor::Windows::AboutWindow::AboutWindow(
    WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument,
    std::function<void()> _close
):Window(
    _context,
    _context->GetDaemon<Daemons::Window::WindowDaemon>()->CreateWindow(
        WeakPointer<Daemons::Window::WindowDef>(
            new Daemons::Window::WindowDef(
                "About Essex Engine Editor - 0.0.1",
                0,
                0,
                400,
                400,
                std::bind(&AboutWindow::WindowClose, this)
            )
        )
    ),
    _close
),label(
    UniquePointer<Daemons::Window::LabelDef>(
        new Daemons::Window::LabelDef(
            "EssexEngine Game Editor",
            50,
            50,
            100,
            100
        )
    )
),button(
    UniquePointer<Daemons::Window::ButtonDef>(
        new Daemons::Window::ButtonDef(
            "button title",
            100,
            310,
            380,
            80,
            std::bind(&AboutWindow::ButtonClick, this)
        )
    )
){
    gameDocument = _gameDocument;

    context->GetDaemon<Daemons::Window::WindowDaemon>()->AddLabel(
        window.ToWeakPointer(),
        label.ToWeakPointer()
    );
    context->GetDaemon<Daemons::Window::WindowDaemon>()->AddButton(
        window.ToWeakPointer(),
        button.ToWeakPointer()
    );
}

void EssexEngine::Apps::Editor::Windows::AboutWindow::WindowClose() {
    close();
}

void EssexEngine::Apps::Editor::Windows::AboutWindow::ButtonClick() {
    close();
}
