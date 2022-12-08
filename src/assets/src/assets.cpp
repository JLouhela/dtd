#include "assets.hpp"

#include <algorithm>
#include <array>

#include "SFML/Graphics.hpp"
#include "loguru/loguru.hpp"

namespace
{

struct TextureResult
{
    bool success{false};
    sf::Texture tex;
};

TextureResult create_texture(const sf::Color& color)
{
    static const int width = 32;
    static const int height = 32;
    sf::Texture texture;
    if (!texture.create(sf::Vector2u{width, height}))
    {
        LOG_F(ERROR, "Could not create empty texture!");
        return TextureResult{};
    }

    std::array<std::uint8_t, width * height * 4> pixels;
    for (int i = 0; i < width * height; ++i)
    {
        const auto idx = i * 4;
        pixels[idx] = color.r;
        pixels[idx + 1] = color.g;
        pixels[idx + 2] = color.b;
        pixels[idx + 3] = color.a;
    }
    texture.update(pixels.data());
    return {true, std::move(texture)};
}
}  // namespace

namespace assets
{

Assets::Assets()
{
    create_color_textures();
}

Load_result Assets::load_texture(const std::string& file_path, const std::string& id)
{
    if (m_textures.count(id) > 0)
    {
        LOG_F(WARNING, "Asset loader: Texture with id %s already exists", id.c_str());
        return Load_result::Failed;
    }

    const auto tex = m_asset_loader.load_texture(file_path);
    if (!tex.success)
    {
        LOG_F(WARNING, "Could not load texture %s from %s", id.c_str(), file_path.c_str());
        return Load_result::Failed;
    }
    LOG_F(INFO, "Loaded texture %s, mapped to id %s", file_path.c_str(), id.c_str());
    m_textures.emplace(id, std::move(tex.texture));
    return Load_result::Ok;
}

// TODO templatize
const sf::Texture* Assets::get_texture(const std::string& id) const
{
    const auto it = m_textures.find(id);
    if (it == m_textures.end())
    {
        LOG_F(WARNING, "Texture %s does not exist!", id.c_str());
        return nullptr;
    }
    return &(it->second);
}

void Assets::create_color_textures()
{
    // TODO consider loop..
    const auto black = create_texture(sf::Color::Black);
    if (black.success)
    {
        m_textures.emplace("texture_black", std::move(black.tex));
    }

    const auto red = create_texture(sf::Color::Red);
    if (red.success)
    {
        m_textures.emplace("texture_red", std::move(red.tex));
    }

    const auto green = create_texture(sf::Color::Green);
    if (green.success)
    {
        m_textures.emplace("texture_green", std::move(green.tex));
    }
}

std::unique_ptr<Assets_interface> make_assets()
{
    return std::make_unique<Assets>();
}

}  // namespace assets