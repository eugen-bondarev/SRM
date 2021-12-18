#include "AssetSupplier.h"

namespace Asu
{
	struct Initializer
	{
		Initializer()
		{
			spdlog::set_pattern("[%^%l%$] %v");
		}
	} initializer;

	AssetSupplier::AssetSupplier(const String& root, const AssetSupplierFlags flags) : root{ root }
	{
		if (flags & AssetSupplierFlags_Create)
		{
			CreateEntryTable(table, root);
			EntryTableToFile(root + "/table.asu", table);
			AssetsToFile(root + "/data.asu", root, table);
		}
		else
		{
			EntryTableFromFile(table, root + "/table.asu");
		}

		if (flags & AssetSupplierFlags_Watch)
		{

		}
	}

	Asset AssetSupplier::Load(const String& location)
	{
		Asset asset;
		const Entry& entry{ FindEntry(location) };
		LoadAsset(asset, root + "/data.asu", entry);
		return asset;
	}

	const Entry& AssetSupplier::FindEntry(const String& location)
	{
		for (size_t i = 0; i < table.size(); ++i)
		{
			if (table[i].GetLocation() == location)
			{
				return table[i];
			}
		}
		// throw
	}
}