//
// Created by hauk on 2023-12-19.
//

#ifndef HAUK_GAME_RESOURCE_RESOURCEHOLDER_HPP
#define HAUK_GAME_RESOURCE_RESOURCEHOLDER_HPP



namespace hauk::game::resource
{

	template <typename Resource, typename Identifier>
	class ResourceHolder
	{
	public:
		void load(Identifier id, const std::string& filename);

		Resource& get(Identifier id);
		const Resource& get(Identifier id) const;
	private:
		void insertResource(Identifier id, std::unique_ptr<Resource> resource);

		std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
	};

} // hauk::game::resource

#include "ResourceHolder.inl"
#endif //HAUK_GAME_RESOURCE_RESOURCEHOLDER_HPP
