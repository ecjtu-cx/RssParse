#include <fstream>
#include <regex>

#include "rssparse.h"
#include "tinyxml2.h"

using std::ofstream;
using std::regex;
using namespace tinyxml2;

string removeHtmlTags(string content) {
  regex rg("<[^>]*>");
  return regex_replace(content, rg, "");
}

RssReader::RssReader() {}

void RssReader::parseRss(const string &filename) {
  XMLDocument doc;
  doc.LoadFile(filename.c_str());

  if (doc.ErrorID() != XML_SUCCESS) {
    std::cerr << "Error loading file: " << filename << std::endl;
    return;
  }

  XMLElement *itemNode = doc.FirstChildElement("rss")
                             ->FirstChildElement("channel")
                             ->FirstChildElement("item");
  while (itemNode) {
    RssItem item;
    item.title = itemNode->FirstChildElement("title")->GetText();
    item.link = itemNode->FirstChildElement("link")->GetText();
    item.description = itemNode->FirstChildElement("description")->GetText();
    item.description = removeHtmlTags(item.description);
    item.content = itemNode->FirstChildElement("content:encoded")->GetText();
    item.content = removeHtmlTags(item.content);
    _rss.push_back(item);
    itemNode = itemNode->NextSiblingElement("item");
  }
}

void RssReader::dump(const string &filename) {
  ofstream ofs(filename);
  if (!ofs) {
    std::cerr << "open file " << filename << " failed" << std::endl;
    return;
  }
  int docid = 1;
  for (const auto &item : _rss) {
    ofs << "<doc>" << std::endl;
    ofs << "\t<docid>" << docid++ << "</docid>" << std::endl;
    ofs << "\t<title>" << item.title << "</title>" << std::endl;
    ofs << "\t<link>" << item.link << "</link>" << std::endl;
    ofs << "\t<description>" << item.description << "</description>"
        << std::endl;
    ofs << "\t<content>" << item.content << "</content>" << std::endl;
    ofs << "</doc>" << std::endl;
  }
}