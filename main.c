void*	malloc(size_t size);
{
	void*	tmp;

	(void) size;
	write(1, "MALLOC CALLED\n", 14);
	tmp = sbrk(size);
	if (tmp == (void*) - 1)
		return (0);
	return (tmp);
}

void	free(void* ptr)
{
	(void) ptr;
	write(1, "FREE CALLED\n", 12);
}

void*	calloc(size_t nmemb, size_t size);
{

}

void*	realloc(void* ptr, size_t size)
{
	void*	tmp;
	size_t	i;

	(void) ptr;
	(void) size;
	write(1, "REALLOC CALLED\n", 15);
	i = 0;
	tmp = malloc(size);
	while (i < size && tmp && ptr)
	{
		*((char*)(tmp + i)) = *((char*)(ptr + i));
		i = i + 1;
	}
	return (tmp);
}
