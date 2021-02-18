#pragma once

//************** Standard Library *****************************
#include <algorithm>

//containers
#include <array>
#include <vector>

//Date time
#include <chrono>


//error handling
#include <stdexcept>

//functional
#include <functional>

//Input Ouput
#include <iostream>
#include <iomanip>

//Numerics Library
#include <ratio>

//Random
#include <random>

//string Library
#include <string>

//thread support Library
#include <future>
#include <thread>

//utilities
#include <memory>


//********************** boost ************************************

//boost gregorian date
#include <boost/date_time/gregorian/gregorian.hpp> //include all types plus i/o

//boost smartptr
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>

//boost UUIDs
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

//boost archive
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

//boost Serialization
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/weak_ptr.hpp>
#include <boost/serialization/vector.hpp>
