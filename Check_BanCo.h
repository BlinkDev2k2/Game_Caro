#pragma once
#define M 17

bool check_ngang(const char a[M][M], const unsigned short int& i, const unsigned short int& j, const char& t, const unsigned short int& x, short int toadothang[10])
{
	unsigned short int dem = 0;
	unsigned short int id = 0;
	for (short int k = j; k >= 0; --k)
	{
		if (a[i][k] == t) {
			++dem;
			toadothang[id] = i;
			++id;
			toadothang[id] = k;
			++id;
		}
		else break;
	}
	if (dem >= 5 || id >= 10) return true;
	for (short int k = j + 1; k < x; ++k)
	{
		if (a[i][k] == t) { 
			++dem;
			toadothang[id] = i;
			++id;
			toadothang[id] = k;
			++id;
		}
		else  break;
	}
	if (dem >= 5 || id >= 10) return true;

	return false;
}

bool check_doc(const char a[M][M], const unsigned short int& i, const unsigned short int& j, const char& t, const unsigned short int& x, short int toadothang[10])
{
	unsigned short int dem = 0;
	unsigned short int id = 0;
	for (short int k = i; k >= 0; --k)
	{
		if (a[k][j] == t)
		{
			++dem;
			toadothang[id] = k;
			++id;
			toadothang[id] = j;
			++id;
		}
		else break;
	}
	if (dem >= 5 || id >= 10) return true;
	for (short int k = i + 1; k < x; ++k)
	{
		if (a[k][j] == t)
		{
			++dem;
			toadothang[id] = k;
			++id;
			toadothang[id] = j;
			++id;
		}
		else  break;
	}
	if (dem >= 5 || id >= 10) return true;

	return false;
}

bool check_cheochinh(const char a[M][M], const unsigned short int& i, const unsigned short int& j, const char& t, const unsigned short int& x, short int toadothang[10])
{
	unsigned short int dem = 0, id = 0;
	short int i1 = i, j1 = j;
	while (1)
	{
		if (a[i1][j1] == t)
		{
			++dem;
			toadothang[id] = i1;
			++id;
			toadothang[id] = j1;
			++id;
		}
		else break;
		--i1;
		--j1;
		if (i1 < 0 || j1 < 0) break;
	}
	if (dem >= 5 || id >= 10) return true;
	i1 = i + 1; j1 = j + 1;
	while (1)
	{
		if (a[i1][j1] == t)
		{
			++dem;
			toadothang[id] = i1;
			++id;
			toadothang[id] = j1;
			++id;
		}
		else break;
		++i1;
		++j1;
		if (i1 > x  || j1 > x ) break;
	}
	if (dem >= 5 || id >= 10) return true;

	return false;
}

bool check_cheophu(const char a[M][M], const unsigned short int& i, const unsigned short int& j, const char& t, const unsigned short int& x, short int toadothang[10])
{
	unsigned short int dem = 0, id = 0;
	short int i1 = i, j1 = j;
	while (1)
	{
		if (a[i1][j1] == t)
		{
			++dem;
			toadothang[id] = i1;
			++id;
			toadothang[id] = j1;
			++id;
		}
		else break;
		++i1;
		--j1;
		if (i1 > x || j1 < 0) break;
	}
	if (dem >= 5 || id >= 10) return true;
	i1 = i - 1; j1 = j + 1;
	while (1)
	{
		if (a[i1][j1] == t)
		{
			++dem;
			toadothang[id] = i1;
			++id;
			toadothang[id] = j1;
			++id;
		}
		else break;
		--i1;
		++j1;
		if (i1 < 0 || j1 > x) break;
	}
	if (dem >= 5 || id >= 10) return true;

	return false;
}