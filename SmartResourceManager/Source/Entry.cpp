#include "Entry.h"

#include "Logging.h"
#include <fstream>
#include "Util.h"

namespace srm
{
	Entry::Entry(const String& location, const size_t size, const size_t offset) : location{ location }, size{ size }, offset{ offset }
	{
		SRM_CONSOLE_INFO("File: %s, size: %i b, offset: %i b", location.c_str(), size, offset);
	}

	void Entry::SetLocation(const String& location)
	{
		this->location = location;
	}

	void Entry::SetSize(const size_t size)
	{
		this->size = size;
	}

	void Entry::SetOffset(const size_t offset)
	{
		this->offset = offset;
	}

	const String& Entry::GetLocation() const
	{
		return location;
	}

	String Entry::GetExtension() const
	{
		return Util::GetExtension(location);
	}

	size_t Entry::GetSize() const
	{
		return size;
	}

	size_t Entry::GetOffset() const
	{
		return offset;
	}

	void LoadAsset(Resource& resource, const String& archivePath, const Entry& entry)
	{
		resource.data.resize(entry.GetSize());

		std::ifstream inputStream{ archivePath, std::ios::binary };
		inputStream.seekg(entry.GetOffset());
		inputStream.read(resource.data.data(), entry.GetSize());
	}


	void LoadEntryList(const String& path)
	{

	}

	void CreateEntryList(const String& root)
	{

	}
}