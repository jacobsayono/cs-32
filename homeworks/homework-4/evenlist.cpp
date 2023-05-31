void removeEven(list<int>& li)
{
    auto it = li.begin();
    while (it != li.end())
    {
        if (*it % 2 == 0)
        {
            it = li.erase(it);
        }
        else
        {
            ++it;
        }
    }
}