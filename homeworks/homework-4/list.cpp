void listAll(const MenuItem* m, string path)
{
    if (m == nullptr)
        return;

    // Append the current menu item's name to the path
    path += m->name();

    // Print the path if it is not empty
    if (!path.empty())
        cout << path << endl;

    // Check if the current menu item is a compound menu
    const vector<MenuItem*>* items = m->menuItems();
    if (items == nullptr)
        return;

    // Recursively call listAll for each submenu
    for (size_t i = 0; i < items->size(); i++)
    {
        listAll((*items)[i], path + "/");
    }
}
