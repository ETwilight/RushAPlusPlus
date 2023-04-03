#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <Video.h>

namespace VideoRecommendation
{
    //typealias
    using VideoId = int;
    using UserId = int;
    using UserHistory = std::map<UserId, std::vector<VideoId>>;

    // Collaborative Filtering
    class ContentBasedFiltering
    {
        double jaccard_similarity(const std::vector<VideoId> &history1, const std::vector<VideoId> &history2)
        {
            std::set<VideoId> set1(history1.begin(), history1.end());
            std::set<VideoId> set2(history2.begin(), history2.end());

            std::vector<VideoId> intersection;
            std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(intersection));

            std::vector<VideoId> union_set;
            std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(union_set));

            if (union_set.size() == 0)
            {
                return 0.0;
            }

            return static_cast<double>(intersection.size()) / static_cast<double>(union_set.size());
        }
        std::vector<VideoId> recommend_videos(const UserHistory &user_history, UserId target_user, int top_k, int k_nearest_neighbors)
        {
            std::vector<std::pair<UserId, double>> user_similarities;

            for (const auto &other_user_history : user_history)
            {
                if (other_user_history.first == target_user)
                {
                    continue;
                }
                double similarity = jaccard_similarity(user_history.at(target_user), other_user_history.second);
                user_similarities.push_back(std::make_pair(other_user_history.first, similarity));
            }

            std::sort(user_similarities.begin(), user_similarities.end(), [](const std::pair<UserId, double> &a, const std::pair<UserId, double> &b)
                      { return a.second > b.second; });

            std::vector<VideoId> recommendations;
            int neighbors_count = 0;

            for (const auto &user_similarity : user_similarities)
            {
                if (neighbors_count >= k_nearest_neighbors)
                {
                    break;
                }

                for (const auto &video_id : user_history.at(user_similarity.first))
                {
                    if (std::find(user_history.at(target_user).begin(), user_history.at(target_user).end(), video_id) == user_history.at(target_user).end())
                    {
                        recommendations.push_back(video_id);
                        neighbors_count++;
                        break;
                    }
                }
            }

            return recommendations;
        }
    };
}