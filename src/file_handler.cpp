#include "file_handler.h"

file_handler::file_handler(std::string path)
: m_path(std::move(path)) {
	m_ifs.open(m_path, std::ios::in);
	if (!m_ifs.is_open())
		return;

	m_contents.clear();
	std::string buf;
	while (getline(m_ifs, buf)) {
		m_contents.push_back(buf);
	}
}

file_handler::~file_handler() {
	if (m_ifs.is_open())
	  m_ifs.close();
	if (m_ofs.is_open())
	  m_ofs.close();
}

void file_handler::write_file() {
	m_ofs.open(m_path, std::ios::out);
	m_ofs.clear();
	for (const auto& content : m_contents)
		m_ofs << content << std::endl;
}
