#include <iostream>
#include <string.h>
#include <memory>
#include "Factory.h"

FactoryManager::~FactoryManager() {}

FactoryManager& FactoryManager::getInstance() {
    static FactoryManager instance;
    return instance;
}

std::unique_ptr<Product> FactoryManager::createProduct(const char type[]) {
    ProductCreator* product_creator_ = nullptr;
    if (!strcmp(type, "ProductA")) {
        product_creator_ = new ProductACreator;
    }
    else if (!strcmp(type, "ProductB")) {
        product_creator_ = new ProductBCreator;
    }
    else {
        product_creator_ = new ProductCCreator;
    }
    std::unique_ptr<Product> ptr(product_creator_->createProduct());
    return ptr;
}

void FactoryManager::assignStrategy(Product* product, const char type[]) {
    /*if (product->process_ != nullptr) {
        delete product->process_;
        product->process_ = nullptr;
    }*/
    ProcessCreator* process_creator_;
    if (!strcmp(type, "Heating")) {
        process_creator_ = new HeatingCreator;
    }
    else if (!strcmp(type, "Cooling")) {
        process_creator_ = new CoolingCreator;
    }
    else {
        process_creator_ = new MixingCreator;
    }
    product->process_ = process_creator_->createProcess();
}


Product::~Product() {}

void ProductA::process() const {
    std::cout << "ProductA ";
    process_->process();
}

void ProductB::process() const {
    std::cout << "ProductB ";
    process_->process();
}

void ProductC::process() const {
    std::cout << "ProductC ";
    process_->process();
}

ProductCreator::~ProductCreator() {}

Product* ProductACreator::createProduct() const {
    return new ProductA;
}

Product* ProductBCreator::createProduct() const {
    return new ProductB;
}

Product* ProductCCreator::createProduct() const {
    return new ProductC;
}


Process::~Process() {}

void Heating::process() const {
    std::cout << "Heated" << std::endl;
}

void Cooling::process() const {
    std::cout << "Cooled" << std::endl;
}

void Mixing::process() const {
    std::cout << "Mixxed" << std::endl;
}

ProcessCreator::~ProcessCreator() {}


Process* HeatingCreator::createProcess() const {
    return new Heating;
}

Process* CoolingCreator::createProcess() const {
    return new Cooling;
}

Process* MixingCreator::createProcess() const {
    return new Mixing;
}