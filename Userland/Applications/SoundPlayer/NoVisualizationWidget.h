/*
 * Copyright (c) 2021, Cesar Torres <shortanemoia@protonmail.com>
 * Copyright (c) 2022, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "VisualizationWidget.h"
#include <LibAudio/Buffer.h>
#include <LibGUI/Frame.h>

class NoVisualizationWidget final : public VisualizationWidget {
    C_OBJECT(NoVisualizationWidget)

public:
    ~NoVisualizationWidget() override = default;
    void set_buffer(RefPtr<Audio::Buffer>) override;
    void start_new_file(StringView) override;

private:
    void paint_event(GUI::PaintEvent&) override;
    NoVisualizationWidget() = default;
    ErrorOr<NonnullRefPtr<Gfx::Bitmap>> get_album_cover(StringView const filename);

    RefPtr<Gfx::Bitmap> m_serenity_bg;
    RefPtr<Gfx::Bitmap> m_album_cover;
};
