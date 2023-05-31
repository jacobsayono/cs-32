void removeBad(list<Restaurant*>& li)
{
    auto it = li.begin();
    while (it != li.end())
    {
        if ((*it)->stars() <= 2)
        {
            delete *it;
            it = li.erase(it);
        }
        else
        {
            ++it;
        }
    }
}