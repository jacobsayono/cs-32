bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
        return true;
    
    maze[sr][sc] = 'O';
    
    //Check South
    if (maze[sr+1][sc] == '.')                //if we can move south and have not encountered it yet
    {
        if (pathExists(maze, sr+1, sc, er, ec) == true) //call pathExists from that position
            return true;
    }

    //Check East
    if (maze[sr][sc+1] == '.')                //if we can move south and have not encountered it yet
    {
        if (pathExists(maze, sr, sc+1, er, ec) == true) //call pathExists from that position
            return true;
    }
    
    //Check North
    if (maze[sr-1][sc] == '.')                //if we can move north and have not encountered it yet
    {
        if (pathExists(maze, sr-1, sc, er, ec) == true) //call pathExists from that position
            return true;
    }

    //Check West
    if (maze[sr][sc-1] == '.')                //if we can move west and have not encountered it yet
    {
        if (pathExists(maze, sr, sc-1, er, ec) == true) //call pathExists from that position
            return true;
    }
    
    return false;
}