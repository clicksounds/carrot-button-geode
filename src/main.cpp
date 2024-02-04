#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/binding/LevelSearchLayer.hpp>
#include <Geode/binding/GJSearchObject.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class Carrot : public CCLayer {
public:
    void carrotButton(CCObject* sender)
	{
		auto searchObj = GJSearchObject::create(SearchType::Search, "carrot");

		auto scene = CCScene::create();
		scene->addChild(LevelBrowserLayer::create(searchObj));
		CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
	}
};

class $modify(LevelSearchLayer) {
	bool init(int p0) {
		if (!LevelSearchLayer::init(p0)) return false;

		auto menu = static_cast<cocos2d::CCMenu*>(this->getChildByID("other-filter-menu"));

		auto spr = CircleButtonSprite::create(CCSprite::create("carrot.png"_spr));
		spr->setScale(0.8f);

		auto btn = CCMenuItemSpriteExtra::create(
			spr, menu, menu_selector(Carrot::carrotButton)
		);
		btn->setID("carot");
		btn->setPosition(ccp(259.500, -14));

		menu->addChild(btn);
		menu->updateLayout();

		return true;
	}
};
