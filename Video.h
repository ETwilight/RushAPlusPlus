class Program::Video
{
    Video();

    Video(std::vector<std::pair<std::string, double>> tag);

    // The intrinsic tag of the Video;
    // Used to make automatic click on the highest matching video;
    private;
    std::string name_;
    std::vector<std::pair<std::string, double>> tag_;
};
