class Program::Page
{
    // Default Constructor for a Page class;
    // Current Usage: The default Page() is used for a new user;
    Page();

    // The Constructor for a Page class that take in a user_id;
    // Current Usage: Generate a Page() for a user with user_id;
    Page(User user_id);

    // A list of videos that is pushed to the user in this Page();
    std::vector<Video> video_list;
        
    // 
    Video currentVideo;
};
