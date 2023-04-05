#include<string>
#include<vector>
#include<map>



class Video{

    public:
        Video();

        Video(std::string category, std::string video_name);

        std::string getName();
        std::string getCategory();

    private:
        std::string video_name_;
        std::string video_category_;

};

class VideoDatabase{
    public:
        VideoDatabase();

        VideoDatabase(std::string file);

        std::string getAll(int label);

        // The intrinsic tag of the Video;
        // Used to make automatic click on the highest matching video;
    private:
        std::vector<Video> video_database_;
};



class UserDatabase{
    public:
        UserDatabase();
        UserDatabase(std::string id, std::vector<std::string> vid_list, int click_count);
        
    private:
        std::vector<User> all_user;
};

class User{

    public:
        // Default Constructor for a User class;
        User();

        User(std::vector<std::string> videos_n_category, std::vector<std::string> videos_n_id);

        // Parameterized Constructor for a User class;
        User(int id, std::vector<std::pair<std::string, double>> preference, int clickcount);

        int id_;
        int clickcount_;
        std::vector<int> clickrecord_;
        std::vector<std::pair<std::string, double>> preference_;
        std::vector<std::string> history_;

};

#include<string>
#include<vector>
#include<map>

class VideDatabase{
    public:
        VideDatabase();

        std::string Get_tag();

        VideDatabase(std::string file);

        VideDatabase(std::vector<std::pair<std::string, double>> tag);

        std::string get_category(int label);

        // The intrinsic tag of the Video;
        // Used to make automatic click on the highest matching video;
    private:
        std::vector<std::pair<std::string, int>> videos_n_id_;
        std::vector<std::pair<std::string, std::string>> videos_n_category_;
        std::vector<std::string> video_names_;
        std::vector<std::string> video_categories_;
        std::vector<int> video_ids_;
};

class UserDatabase{
    public:
        UserDatabase();
        UserDatabase(std::string id, std::vector<std::string> vid_list, int click_count);
        class EachUser{
            public:
                EachUser();
                EachUser(std::vector<std::string> videos_n_category, std::vector<std::string> videos_n_id);
                std::string getId();
                std::vector<std::pair<std::string, double>> getPreference();
                std::vector<std::string> getHistory();
            private:
                std::string user_id_;
                std::vector<std::string> history_;
                std::vector<std::pair<std::string, double>> preference_;

        };
        
    private:
        std::vector<UserDatabase::EachUser> all_user;
};
