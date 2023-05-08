#pragma once
#include <fstream>
#include <vector>
#include <string>

class file_handler {
public:
	explicit file_handler(std::string path);
	~file_handler();
	file_handler(const file_handler&) = delete;
	file_handler(file_handler&&) = delete;

	file_handler& operator=(const file_handler&) = delete;
	file_handler& operator=(file_handler&&) = delete;

	std::vector<std::string> get_contents() { return m_contents; }
	void set_contents(std::vector<std::string> contents) { m_contents = std::move(contents); }
	void write_file();

private:
	std::ifstream m_ifs;
	std::ofstream m_ofs;
	std::vector<std::string> m_contents;
	std::string m_path;
};