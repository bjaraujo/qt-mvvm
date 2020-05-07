// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant/CsvReader.cpp
//! @brief     Implements class CsvReader
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "csvfile.h"

#include <fstream>
#include <iostream>

namespace DataImportLogic
{

//! The constructor
CSVFile::CSVFile(std::string path_to_file) : m_filepath(path_to_file)
{
    loadFile();
    generateThumbnail();
}

//! Generate the thumbnail
void CSVFile::loadFile()
{
    m_file.clear();
    std::ifstream file(m_filepath);
    std::string line;
    while (getline(file, line)) {
        m_file.push_back(line);
        ;
    };
    file.close();
}

//! The getter for the thumbnail text
const std::vector<std::string>& CSVFile::thumbnail() const
{
    return m_thumbnail;
}

//! The getter for the thumbnail text
const std::vector<std::string>& CSVFile::file() const
{
    return m_file;
}

//! Generate the thumbnail
void CSVFile::generateThumbnail()
{
    m_thumbnail.clear();
    m_thumbnail.resize(m_thumbnail_length);

    std::ifstream file(m_filepath);
    int counter = 0;
    while (counter != m_thumbnail_length) {
        getline(file, m_thumbnail[counter]);
        counter++;
    };
    file.close();
}

//! Return a precise line
const std::string& CSVFile::line(int line_number) const
{
    return m_file.at(line_number);
}

// std::string const& CSVRow::operator[](unsigned index) const
// {
//     return m_data[index];
// }

// unsigned long CSVRow::size() const
// {
//     return static_cast<unsigned long>(m_data.size());
// }

// void CSVRow::readNextRow(std::istream& str)
// {
//     std::string line;
//     std::getline(str, line);
//     std::replace(std::begin(line), std::end(line), '\t', ' ');
//     std::stringstream lineStream(line);
//     std::string cell;

//     m_data.clear();

//     while (std::getline(lineStream, cell, separator)) {
//         addCell(cell);
//     }
//     // This checks for a trailing comma with no data after it.
//     if (!lineStream && cell.empty()) {
//         // If there was a trailing comma then add an empty element.
//         addCell("");
//     }
// }

// void CSVRow::setSeparator(char sep)
// {
//     this->separator = sep;
//     return;
// }

// char CSVRow::getSeparator()
// {
//     return this->separator;
// }

// void CSVRow::addCell(std::string str)
// {
//     m_data.push_back(str);
// }

// void CSVFile::Init()
// {
//     Read();
//     EqualizeRowLengths();
// }

// void CSVFile::Read()
// {
//     std::ifstream file(filepath);
//     if (!file.is_open()) {
//         throw std::ios_base::failure("Unable to open file \"" + filepath + "\"");
//     }
//     for (CSVIterator loop(file, separator); loop != CSVIterator(); ++loop) {
//         rows.push_back((*loop));
//         numberOfColumns =
//             (*loop).size() > numberOfColumns ? unsigned((*loop).size()) : numberOfColumns;
//     }
// }

// void CSVFile::EqualizeRowLengths()
// {
//     for (unsigned i = 0; i < NumberOfRows(); i++) {
//         while (rows[i].size() < NumberOfColumns()) {
//             rows[i].addCell("");
//         }
//     }
//     for (unsigned i = 0; i < NumberOfRows(); i++) {
//         m_data.push_back(rows[i].dataVector());
//     }
// }

// std::vector<std::string> const CSVFile::operator[](unsigned index_i) const
// {
//     return m_data[index_i];
// }

// unsigned long CSVFile::NumberOfRows() const
// {
//     return static_cast<unsigned long>(rows.size());
// }

// unsigned long CSVFile::NumberOfColumns() const
// {
//     return this->numberOfColumns;
// }

// void CSVFile::set_separator(char sep)
// {
//     this->separator = sep;
//     return;
// }

// char CSVFile::get_separator()
// {
//     return this->separator;
// }

// CSVRow CSVFile::get_headers()
// {
//     if (headersRow > 0) {
//         return this->rows[headersRow - 1];
//     } else {
//         CSVRow dummy;
//         while (dummy.size() < NumberOfColumns())
//             dummy.addCell("");
//         return dummy;
//     }
// }

// CSVRow CSVFile::get_row(unsigned i)
// {
//     return this->rows[i];
// }

} // namespace DataImportLogic
