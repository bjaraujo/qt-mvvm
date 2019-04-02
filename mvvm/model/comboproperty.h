// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/ComboProperty.h
//! @brief     Defines class ComboProperty
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef COMBOPROPERTY_H
#define COMBOPROPERTY_H

#include "global.h"
#include <QVariant>
#include <string>
#include <vector>

//! Custom property to define list of string values with multiple selections.
//! Intended for QVariant.

class CORE_EXPORT ComboProperty
{
public:
    ComboProperty();

    static ComboProperty fromList(const std::vector<std::string>& values,
                                  const std::string& current_value = {});

    std::string getValue() const;
    void setValue(const std::string& name);

    std::vector<std::string> getValues() const;
    void setValues(const std::vector<std::string>& values);

    std::vector<std::string> toolTips() const;
    void setToolTips(const std::vector<std::string>& tooltips);

    int currentIndex() const;
    void setCurrentIndex(int index);

    ComboProperty& operator<<(const std::string& str);
    ComboProperty& operator<<(const std::vector<std::string>& str);
    bool operator==(const ComboProperty& other) const;
    bool operator!=(const ComboProperty& other) const;
    bool operator<(const ComboProperty& other) const;

    std::string stringOfValues() const;
    void setStringOfValues(const std::string& values);

    QVariant variant() const;

    std::vector<int> selectedIndices() const;
    std::vector<std::string> selectedValues() const;

    void setSelected(int index, bool value = true);
    void setSelected(const std::string& name, bool value = true);

    std::string stringOfSelections() const;
    void setStringOfSelections(const std::string& values);

    std::string label() const;

private:
    ComboProperty(std::vector<std::string> values);

    std::vector<std::string> m_values;
    std::vector<std::string> m_tooltips;
    std::vector<int> m_selected_indices;
};

Q_DECLARE_METATYPE(ComboProperty)

#endif // COMBOPROPERTY_H
