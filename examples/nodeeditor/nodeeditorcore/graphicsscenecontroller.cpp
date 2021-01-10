// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "graphicsscenecontroller.h"
#include "graphicsscene.h"
#include "samplemodel.h"

namespace NodeEditor {

GraphicsSceneController::GraphicsSceneController(SampleModel* model, GraphicsScene* scene)
    : ModelView::ModelListener<SampleModel>(model), m_scene(scene)
{
    setOnItemInserted([this](auto, auto) { m_scene->updateScene(); });
}

} // namespace NodeEditor