add_library(myassets STATIC
    assing_dim_for_an_asset.c
    assing_dimensions_for_4_assets.c
    free_4_assets.c
    free_an_asset.c
    load_4_assets.c
    load_an_asset.c
)

target_include_directories(myassets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
