#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
public:
	Exception(int line, const wchar_t* file) noexcept;
	const wchar_t* Message() const noexcept;
	virtual const wchar_t* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	mutable std::string messageBuffer;
};