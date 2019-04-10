#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <array>

template<typename S_Iterator, typename T_Iterator>
size_t LongestSubsequence(S_Iterator s_begin, S_Iterator s_end, T_Iterator t_begin, T_Iterator t_end)
{
	if (s_end == s_begin || t_end == t_begin)
	{
		return 0;
	}

	if (*s_begin == *t_begin)
	{
		return 1 + LongestSubsequence(++s_begin, s_end, ++t_begin, t_end);
	}

	return std::max(LongestSubsequence(++s_begin, s_end, t_begin, t_end),
		LongestSubsequence(s_begin, s_end, ++t_begin, t_end));
}

int main()
{
	std::vector<int> s;
	std::array<int, 8> t;

	s.resize(6);

	s[0] = 'A';
	s[1] = 'B';
	s[2] = 'A';
	s[3] = 'Z';
	s[4] = 'D';
	s[5] = 'C';

	t[0] = 'B';
	t[1] = 'A';
	t[2] = 'C';
	t[3] = 'B';
	t[4] = 'A';
	t[5] = 'D';
	t[6] = 'D';
	t[7] = 'C';

	std::cout << LongestSubsequence(s.begin(), s.end(), t.begin(), t.end()) << std::endl;

	system("pause");
}
