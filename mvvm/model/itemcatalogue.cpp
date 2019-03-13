// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "itemcatalogue.h"
#include "ifactory.h"
#include "sessionitem.h"

using namespace ModelView;


class ModelView::ItemCatalogueImpl {
public:
    IFactory<std::string, SessionItem> factory;
};

ItemCatalogue::ItemCatalogue()
    : m_data(new ItemCatalogueImpl)
{

}

void ItemCatalogue::add(const std::string& model_type, ItemCatalogue::factory_func_t func)
{
    m_data->factory.add(model_type, func);
}

ItemCatalogue::~ItemCatalogue() = default;

bool ItemCatalogue::contains(const std::string& model_type) const
{
    return m_data->factory.contains(model_type);
}

std::unique_ptr<SessionItem> ItemCatalogue::create(const std::string& model_type) const
{
    return m_data->factory.create(model_type);
}