#include "assets.hpp"

#include <algorithm>

#include "loguru/loguru.hpp"

namespace assets
{

Assets::Assets()
{
}

Load_result Assets::load_texture(const std::string& file_path, const std::string& id)
{
    if (m_textures.count(id) > 0)
    {
        LOG_F(WARNING, "Asset loader: Texture with id %s already exists", id.c_str());
        return Load_result::Failed;
    }

    std::unique_ptr<sf::Texture> tex = m_asset_loader.load_texture(file_path);
    if (!tex)
    {
        LOG_F(WARNING, "Could not load texture %s from %s", id.c_str(), file_path.c_str());
        return Load_result::Failed;
    }
    LOG_F(INFO, "Loaded texture %s, mapped to id %s", file_path.c_str(), id.c_str());
    m_textures.emplace(id, std::move(tex));
    return Load_result::Ok;
}

// TODO templatize
sf::Texture* Assets::get_texture(const std::string& id) const
{
    const auto it = m_textures.find(id);
    if (it == m_textures.end())
    {
        LOG_F(WARNING, "Texture %s does not exist!", id.c_str());
        return nullptr;
    }
    return &(*it->second);
}

std::unique_ptr<Assets_interface> make_assets()
{
    return std::make_unique<Assets>();
}

}  // namespace assets