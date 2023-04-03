#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

namespace RecommendationAlgorithms
{
    //Content-based recommendation algorithm
    class ContentBasedFiltering
    {
        double jaccard_similarity(const std::set<std::string> &set1, const std::set<std::string> &set2)
        {
            size_t intersection_count = 0;
            size_t union_count = 0;

            for (const auto &element : set1)
            {
                if (set2.find(element) != set2.end())
                {
                    intersection_count++;
                }
                union_count++;
            }

            for (const auto &element : set2)
            {
                if (set1.find(element) == set1.end())
                {
                    union_count++;
                }
            }

            return static_cast<double>(intersection_count) / static_cast<double>(union_count);
        }
        std::vector<int> recommend_videos(const std::vector<Video> &videos, int target_video_id, int top_k)
        {
            std::vector<std::pair<int, double>> similarity_scores;

            for (size_t i = 0; i < videos.size(); i++)
            {
                if (i == target_video_id)
                {
                    continue;
                }

                double similarity = jaccard_similarity(videos[target_video_id].tags, videos[i].tags);
                similarity_scores.push_back(std::make_pair(i, similarity));
            }

            std::sort(similarity_scores.begin(), similarity_scores.end(), [](const std::pair<int, double> &a, const std::pair<int, double> &b)
                      { return a.second > b.second; });

            std::vector<int> recommendations;
            for (int i = 0; i < top_k && i < static_cast<int>(similarity_scores.size()); i++)
            {
                recommendations.push_back(similarity_scores[i].first);
            }

            return recommendations;
        }
    };
}