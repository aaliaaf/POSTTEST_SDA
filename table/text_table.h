#ifndef TEXT_TABLE_H
#define TEXT_TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class TextTable {
public:
    enum class Alignment { LEFT, RIGHT };
    
private:
    vector<vector<string>> _rows;
    vector<Alignment> _alignment;
    char _horizontal, _vertical, _corner;
    
public:
    TextTable(char horizontal = '-', char vertical = '|', char corner = '+')
        : _horizontal(horizontal), _vertical(vertical), _corner(corner) {}
    
    void add(string const& content) {
        if (_rows.empty()) _rows.push_back(vector<string>());
        _rows.back().push_back(content);
    }
    
    void add(vector<string> const& row) {
        if (_rows.empty()) _rows.push_back(vector<string>());
        for (auto const& cell : row) _rows.back().push_back(cell);
    }
    
    void endOfRow() { _rows.push_back(vector<string>()); }
    
    void setAlignment(unsigned int column, Alignment alignment) {
        while (_alignment.size() <= column) _alignment.push_back(Alignment::LEFT);
        _alignment[column] = alignment;
    }
    
    friend ostream& operator<<(ostream& os, TextTable const& table) {
        if (table._rows.empty()) return os;
        
        vector<unsigned int> widths(table._rows[0].size(), 0);
        for (auto const& row : table._rows)
            for (unsigned int i = 0; i < row.size(); ++i)
                widths[i] = max(widths[i], (unsigned int)row[i].length());
        
        os << table._corner;
        for (unsigned int i = 0; i < widths.size(); ++i) {
            for (unsigned int j = 0; j < widths[i] + 2; ++j) os << table._horizontal;
            os << table._corner;
        }
        os << "\n";
        
        for (auto const& row : table._rows) {
            if (row.empty()) continue;
            os << table._vertical;
            for (unsigned int i = 0; i < row.size(); ++i) {
                os << " ";
                if (i < table._alignment.size() && table._alignment[i] == TextTable::Alignment::RIGHT)
                    os << setw(widths[i]) << row[i];
                else
                    os << left << setw(widths[i]) << row[i];
                os << " " << table._vertical;
            }
            os << "\n";
            
            os << table._corner;
            for (unsigned int i = 0; i < widths.size(); ++i) {
                for (unsigned int j = 0; j < widths[i] + 2; ++j) os << table._horizontal;
                os << table._corner;
            }
            os << "\n";
        }
        return os;
    }
};

#endif