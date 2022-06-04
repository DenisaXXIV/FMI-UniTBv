using AutoMapper;
using Hotel_WPF.BL.Interfaces;
using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.TL.DTO;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Classes
{
    public class FacilitiesLogic : IEntityLogic<FacilitiesDTO>
    {
        private readonly IHotelRepository<Facilities> _facilitiesRepository;
        private readonly IMapper _mapper;

        public FacilitiesLogic(IHotelRepository<Facilities> facilitiesRepository, IMapper mapper)
        {
            _facilitiesRepository = facilitiesRepository;
            _mapper = mapper;
        }

        public async Task Add(FacilitiesDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Facilities>(entityDTO);
                await _facilitiesRepository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<FacilitiesDTO>> GetAll()
        {
            var results = _mapper.Map<List<FacilitiesDTO>>(await _facilitiesRepository.GetAll());
            return results;
        }

        public async Task<FacilitiesDTO> GetByName(string name)
        {
            if (name == null)
            {
                throw new ArgumentNullException(nameof(name));
            }
            FacilitiesDTO result;
            try
            {
                var results = _mapper.Map<List<FacilitiesDTO>>(await _facilitiesRepository.GetAll());
                result = results.FirstOrDefault(a => a.Name == name);
                if (result == null)
                {
                    throw new DbUpdateException();
                }
                return result;
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task Remove(FacilitiesDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _facilitiesRepository.Delete(entityDTO.IdFacilities);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(FacilitiesDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Facilities>(entityDTO);
                await _facilitiesRepository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }
    }
}
