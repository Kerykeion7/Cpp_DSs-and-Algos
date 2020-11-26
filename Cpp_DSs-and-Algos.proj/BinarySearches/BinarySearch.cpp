int IndexOf(int array[], int left, int right, int key) {
	int index = (int)((right - left) / 2);
	if (index <= left) index += left;
	int value = array[index];

	if (key < value) return IndexOf(array, left, index, key);
	if (key > value) return IndexOf(array, index, right, key);
	if (key == value) return index;
	return -1;
}