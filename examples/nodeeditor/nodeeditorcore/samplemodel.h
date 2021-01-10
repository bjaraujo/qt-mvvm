// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef NODEEDITORCORE_SAMPLEMODEL_H
#define NODEEDITORCORE_SAMPLEMODEL_H

#include "mvvm/model/compounditem.h"
#include "mvvm/model/sessionmodel.h"
#include <string>

namespace NodeEditor {

//! Main application model.

class SampleModel : public ModelView::SessionModel {
public:
    SampleModel();

private:
    void createInitialContent();
};

} // namespace NodeEditor

#endif // NODEEDITORCORE_SAMPLEMODEL_H