// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_MOUSEPOSINFO_H
#define MVVM_MOUSEPOSINFO_H

#include "mvvm_export.h"

class QCustomPlot;

namespace ModelView
{

/*!
@struct MousePoseInfo
@brief Aggregate to hold mouse position info in QCustomPlot context.

Position is given in axis coordinates corresponding to the current zoom level.
*/

struct CORE_EXPORT MousePosInfo
{
    double xpos{0.0};
    double ypos{0.0};
    bool in_axes_range{false};
};

} // namespace ModelView

#endif // MVVM_MOUSEPOSINFO_H
