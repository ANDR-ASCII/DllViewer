#pragma once

#include <map>

namespace BaseApi
{
	template<typename T>
	class ICreator
	{
	public:
		virtual std::shared_ptr<T> create() const = 0;
	};

	template<typename Base, typename CreateType>
	class Creator : public ICreator<Base>
	{
	public:
		virtual std::shared_ptr<Base> create() const override
		{
			return std::make_shared<CreateType>();
		}
	};

	template<typename Key, typename T>
	class Factory final
	{
	public:
		std::shared_ptr<T> create(Key const& key) const
		{
			auto iter = m_storage.find(key);

			if (iter != m_storage.end())
			{
				return iter->second->create();
			}

			return nullptr;
		}

		template<typename U>
		bool registrate(Key const& key)
		{
			auto iter = m_storage.find(key);

			if (iter == m_storage.end())
			{
				m_storage[key] = std::make_shared<Creator<T, U>>();
				return true;
			}

			return false;
		}

	private:
		std::map<Key, std::shared_ptr<ICreator<T>>> m_storage;
	};
}