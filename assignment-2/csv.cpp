#include "csv.h"

using namespace std;


/**
 * Parses a line/record of a csv file, returning one string for each
 * field in the record.
*/
std::vector<std::string> parseCSV (const std::string& line)
{
  vector<string> results;
  string field;
  bool seenQuote = false;
  for (int i = 0; i < line.size(); ++i)
    {
      char c = line[i];
      if (c == '"') 
	{
	  if (seenQuote && i < line.size() && line[i+1] == '"')
	    {
	      // A double quote "" is treated as a single quote character
	      field += c;
	      ++i;
	    } 
	  else 
	    {
	      // Otherwise, this quote character begins or ends a quoted string
	      seenQuote = !seenQuote;
	  }
	}
      else if (c == ',' && !seenQuote)
	{
	  results.push_back(field);
	  field = "";
	}
      else
	field += c;
    }
  if (!seenQuote)
    results.push_back(field);
  return results;
}


