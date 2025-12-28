#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// バブルソート(引数が不適切であればfalseを返す)
bool bubble_sort(item* begin, const item* end)
{
	if (!begin || !end || begin > end)
		return false;

	if (end - begin < 2)
		return true;

	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (item* p = begin; p + 1 < end; ++p)
		{
			if (p->key > (p + 1)->key)
			{
				item tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
				swapped = true;
			}
		}
		--end;
	}

	return true;
}