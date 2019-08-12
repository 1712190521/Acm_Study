int getmin(char *s) {
	int n = strlen(s);
	int i = 0, j = 1, k = 0, t;
	while (i < n && j < n && k < n) {
		t = s[(i + k) % n] - s[(j + k) % n];
		if (!t) k++;
		else {
			if (t > 0) i += k + 1;
			else j += k + 1;
			if (i == j) j++;
			k = 0;
		}
	}
	return i < j ? i : j;
}
有一个字符串，这个字符串的首尾是连在一起的，要求寻找一个位置，以该位置为起点的字符串的字典序在所有的字符串中中最小。