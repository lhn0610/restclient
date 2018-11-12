#include "restclient.h"
#include <gtest/gtest.h>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


class RestAPITest : public ::testing::Test
{
protected:

	RestAPITest()
	{
	}

	virtual ~RestAPITest()
	{
	}

	virtual void SetUp()
	{
		RestClient::init();
	}

	virtual void TearDown()
	{
		RestClient::disable();
	}

};

/********** GET SN TEST **********/
TEST_F(RestAPITest, RestAPI_SN_GET_Code)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/sn");
	EXPECT_EQ(200, res.code);
}

TEST_F(RestAPITest, TestResAPI_SN_GET_Body)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/sn");
	json root=json::parse(res.body);
	EXPECT_EQ("ASDC2345", root["sn"]);
}

TEST_F(RestAPITest, RestAPI_SN_GET_Headers)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/sn");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}




/********* PUT SN TEST *********/
TEST_F(RestAPITest, RestAPI_SN_PUT_Code)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/sn", "application/json", "{\"sn\":\"ASDC2345\"}");
	EXPECT_EQ(200, res.code);
}

TEST_F(RestAPITest, RestAPI_SN_PUT_Body)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/sn", "application/json", "{\"sn\":\"ASDC2345\"}");
	json root = json::parse(res.body);
	EXPECT_EQ("ASDC2345", root["sn"]);
}

TEST_F(RestAPITest, RestAPI_SN_PUT_Headers)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/sn", "application/json", "{\"sn\":\"ASDC2345\"}");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}




/********* GET VERSION TEST *********/
TEST_F(RestAPITest, RestAPI_VER_GET_Code)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/ver");
	EXPECT_EQ(200,res.code);
}

TEST_F(RestAPITest, RestAPI_VER_GET_Body)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/ver");
	json root = json::parse(res.body);
	EXPECT_EQ("1.2.3.4",root["fw_version"]);
	EXPECT_EQ("1", root["api_version"]);
}

TEST_F(RestAPITest, RestAPI_VER_GET_Headers)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/ver");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}



/********* PUT VERSION TEST *********/
TEST_F(RestAPITest,RestAPI_VER_PUT_Code)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/ver","application/json","{\"fw_version\":\"1.2.3.4\",\"api_version\":\"1\"}");
	EXPECT_EQ(200,res.code);
}

TEST_F(RestAPITest,RestAPI_VER_PUT_Body)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/ver", "application/json", "{\"fw_version\":\"1.2.3.4\",\"api_version\":\"1\"}");
	json root = json::parse(res.body);
	EXPECT_EQ("1.2.3.4",root["fw_version"]);
	EXPECT_EQ("1", root["api_version"]);
}

TEST_F(RestAPITest,RestAPI_VER_PUT_Headers)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/ver", "application/json", "{\"fw_version\":\"1.2.3.4\",\"api_version\":\"1\"}");
	EXPECT_EQ("Keep-Alive",res.headers["Connection"]);
}



/********* GET TIME TEST *********/
TEST_F(RestAPITest,RestAPI_TIME_GET_Code)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/time");
	EXPECT_EQ(200, res.code);
}

TEST_F(RestAPITest, RestAPI_TIME_GET_Headers)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/time");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}




/********* PUT ITME TEST *********/
TEST_F(RestAPITest,RestAPI_TIME_PUT_Code)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/time", "application/json", "{\"epoch_time\":\"13343435459\"}");
	EXPECT_EQ(200,res.code);
}

TEST_F(RestAPITest, RestAPI_TIME_PUT_Headers)
{
	RestClient::Response res = RestClient::put("http://192.168.1.100/v1/time", "Application/json", "{\"epoch_time\":\"13343435459\"}");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}




/******** POST CAPTURE TEST ********/
TEST_F(RestAPITest, RestAPI_CAPTURE_POST_Code)
{
	RestClient::Response res = RestClient::post("http://192.168.1.100/v1/capture", "application/json", "");
	EXPECT_EQ(200, res.code);
}

TEST_F(RestAPITest, RestAPI_CAPTURE_POST_Headers)
{
	RestClient::Response res = RestClient::post("http://192.168.1.100/v1/capture", "application/json", "");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}




/********* GET CAPTURE TEST *********/
TEST_F(RestAPITest, RestAPI_CAPTURE_GET_Code)
{
	RestClient::Response res_post = RestClient::post("http://192.168.1.100/v1/capture", "application/json", "");
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/capture");
	EXPECT_EQ(200,res.code);
}

TEST_F(RestAPITest, RestAPI_CAPTURE_GET_Headers)
{
	RestClient::Response res = RestClient::get("http://192.168.1.100/v1/capture");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}




/********* DELETE CAPTURE TEST *********/
TEST_F(RestAPITest, RestAPI_CAPTURE_DELETE_Code)
{
	RestClient::Response res = RestClient::del("http://192.168.1.100/v1/capture");
	EXPECT_EQ(200, res.code);
}

TEST_F(RestAPITest, RestAPI_CAPTURE_DELETE_Headers)
{
	RestClient::Response res = RestClient::del("http://192.168.1.100/v1/captures");
	EXPECT_EQ("Keep-Alive", res.headers["Connection"]);
}


