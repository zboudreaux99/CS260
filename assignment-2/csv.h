#ifndef CSV_H
#define CSV_H

#include <string>
#include <vector>

/**
 * Parses a line/record of a csv file, returning one string for each
 * field in the record.
*/
std::vector<std::string> parseCSV (const std::string& line);

#endif
