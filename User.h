#include <vector>
#include <string>

class User
{
    // Default Constructor for a User class;
    User();

    // Parameterized Constructor for a User class;
    User(int id, std::vector<std::pair<std::string, double>> preference, int clickcount);

    public:
    // The variable that states the id (index) of the user;
    int id;

    private:
    // The variable that defines user preference to each kind of video;
    // Used to make automatic click on the highest matching video;
    std::vector<std::pair<std::string, double>> preference;

    public:
    // The variable that tracks the click count of the user;
    // Used to decide the weight on whether to change our user sculpture;
    int clickcount;

    // The variable that tracks the click record of the user;
    // The clickrecord.size() = number of all videos;
    // Each stored int is the time of the click the user did on the corresponding video, used to be compared with clickcount to decide
    // whether the video can be shown again to this user;
    std::vector<int> clickrecord;
};
