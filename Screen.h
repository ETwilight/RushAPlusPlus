class Program::Screen
{
    // Default Constructor for a Screen class;
    Screen();

    // Update the current_user_;
    void updateUser(User user_id);

    // Simulate 1 click and update the current_page_;
    void clickOnce(int ith);

    // Simulate n clicks and update the current_page_;
        void clickNTimes(int n);

    // The variable that sill be displayed on the screen;
    Page current_page_;

    // THe variable that states which User is using the Screen;
    User current_user_;

};
