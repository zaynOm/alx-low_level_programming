int number_len(int x)
{
    int i = 1;
    
    while(x > 0)
    {
        x = x / 10;
        i *= 10;
    }
    i = i / 10;
    
    return i;
}
